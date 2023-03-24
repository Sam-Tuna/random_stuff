name_file = "path/to/name/file"
blastoutfile = "path/to/blast/file"

#get names from file
with open (name_file) as namin:
    names = namin.readlines()
namin.close
namesplit = []
for i in names:
    namesplit.append(i[1:].split(" ", 1))
#parse the blast output
with open (blastoutfile) as blastin:
    blast = blastin.readlines()
blastin.close
blastsplit = []
for i in blast:
    blastsplit.append(i.split("\t", 1))
#extend the names
blastex = []
for i in blastsplit:
    for j in namesplit:
        if (j[0]==i[0]):
            line = [" ".join(j), i[1]]
            line[0] = line[0].replace("\n", "")
            blastex.append("\t".join(line))
#saves output            
with open ("extended_names.tsv", "w") as out:
    for i in blastex:
        out.write(i)
out.close
