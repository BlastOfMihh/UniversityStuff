#!/usr/bin/env python3
import unittest


class testus(unittest.TestCase):
    variable=True
    cineva="Altcineva"
    def test1(self):
        self.assertTrue(self.variable==False)
    def test2(self):
        self.assertTrue(False, self.cineva)

uni_test=testus()
unittest.main()
