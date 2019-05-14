#!/usr/bin/python
import subprocess, os, sys
code_dir = "code"
title = "3N1?M4 Team Reference"

# TODO: check if this is everything we need
def texify(s):
    #s = s.replace('\'', '\\\'')
    #s = s.replace('\"', '\\\"')
    return s

if __name__ == "__main__":
    latexmk_options = ["latexmk", "-pdf", "notebook.tex"]
    subprocess.call(latexmk_options)
    subprocess.call(["okular", "notebook.pdf"])
    
