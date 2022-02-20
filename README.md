# random_stuff
Random small programs i wrote for various reasons and want to keep track of, mostly related to bioinformatics.

### faixa.R
Small R program that calculates enzimatic parameters of a luciferase with substrate inhibition using non linear least squares. The input is an excel tables with light emission per time. This is very specific program for the experiments that I did, and it's not meant to be a general enzimatic parameter calculator.

### aligner.c
Rustic aminoacid aligner that reads fasta sequences and outputs the best alignment it could make from them, using the Needleman-Wunsch algorithm.

### line_breaker.c
Tiny program that adds line breaks after each word in a name list separated by spaces.

### reader.py
Reads all Water aminoacid alignments (ending with .align) in a directory and outputs a file with the summary of each in descendent order by score.

### extnames.py
The BLAST tabular output can trim the names of the sequences if they're too long. This program takes a list of the full names and rewrites the output so the names are complete.
