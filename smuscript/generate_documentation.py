# This file is part of the SmuView project.
#
# Copyright (C) 2019-2020 Frank Stettner <frank-stettner@gmx.net>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import smuview
import sys
import pydoc
import pdoc
import re

#
# pydoc
#

# Write to text file
#file_name = './smuview_python_bindings_pydoc.txt'
#f = open(file_name, 'w')
#sys.stdout = f
#pydoc.help(smuview)
#f.close()
#sys.stdout = sys.__stdout__

# Write html file to current directory
#pydoc.writedoc(smuview)


#
# pdoc3
#
# Install:
#   $ pip3 install pdoc3
#

html_str = pdoc.html("smuview", show_type_annotations=True)
file_name = './smuview_python_bindings_pdoc3.html'
f = open(file_name, 'w')
print(html_str, file=f)
f.close()
