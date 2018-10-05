import unittest
from stack import *


class StackTest(unittest.TestCase):
    def test_pop_from_empty(self):
        s = Stack()
        self.assertRaises(Exception, s.pop)

    def test_pop_from_nonempty(self):
        s = Stack()
        s.push(88)
        actual = s.pop()
        self.assertEqual(actual, 88)
