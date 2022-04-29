##############################################################################
#
#     parser.py
#     Copyright (c) 2020 Raphael DINGE
#
#Tab=3########################################################################



from .arpeggio import ParserPython, visit_parse_tree, NoMatch

from . import error
from .grammar import GRAMMAR_ROOT, GRAMMAR_MANUFACTURER_ROOT, comment
from .visitor import Visitor
from .analyser import Analyser
from . import adapter

import os

PATH_THIS = os.path.abspath (os.path.dirname (__file__))
PATH_ROOT = os.path.abspath (os.path.dirname (os.path.dirname (PATH_THIS)))
PATH_BOARDS = os.path.join (PATH_ROOT, 'boards')



class Parser:
   def __init__ (self, grammar_root=GRAMMAR_ROOT):
      self._parser = ParserPython (grammar_root, comment, autokwd=True)

   def parse (self, input_text, file_name):
      parse_tree = self._get_parse_tree (input_text, file_name)
      ast = self._get_ast (parse_tree, file_name)

      for import_ in ast.imports:
         self._merge_import (ast, import_)

      for module in ast.modules:
         self._merge_super (module)

      return self._analyse_ast (ast)

   def parse_manufacturer (self, input_text, file_name):
      parse_tree = self._get_parse_tree (input_text, file_name)
      return self._get_ast (parse_tree, file_name)

   def _merge_import (self, node, import_):
      import_path = import_.path
      try:
         file = open (import_path, 'r', encoding='utf-8')
      except OSError:
         err = error.Error ()
         context = import_.source_context
         err.add_error ("Cannot open file for import '%s'" % context, context)
         err.add_context (context)
         raise err

      with file:
         input_text = file.read ()

      import_parser = Parser (grammar_root=GRAMMAR_MANUFACTURER_ROOT)
      import_ast = import_parser.parse_manufacturer (input_text, import_path)

      node.entities.extend (import_ast.entities)

   def _merge_super (self, module):
      if module.super_identifier is None:
         return

      path_layout = os.path.join (PATH_BOARDS, module.super_identifier.name, 'layout.erbui')

      try:
         file = open (path_layout, 'r', encoding='utf-8')
      except OSError:
         err = error.Error ()
         context = module.super_identifier
         err.add_error ("Undefined board layout for '%s'" % context, context)
         err.add_context (context)
         raise err

      with file:
         input_text = file.read ()

      file_name = os.path.basename (path_layout)

      parse_tree = self._get_parse_tree (input_text, file_name)
      ast = self._get_ast (parse_tree, path_layout)
      module.entities.extend (ast.modules [0].entities)

   def _get_parse_tree (self, input_text, file_name):
      try:
         cst = self._parser.parse (input_text, file_name)
         return cst
      except NoMatch as err:
         raise error.ParseError (err)

   def _get_ast (self, parse_tree, file_name):
      visitor = Visitor (self._parser)
      visitor.set_filename (file_name)
      ast = visit_parse_tree (parse_tree, visitor)
      return ast

   def _analyse_ast (self, ast):
      analyser = Analyser ()
      analyser.analyse (ast)
      return ast
