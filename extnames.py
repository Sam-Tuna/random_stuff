#get names from file
with open ("UniVec/names.txt") as namin:
    names = namin.readlines()
namin.close
namesplit = []
for i in names:
    namesplit.append(i[1:].split(" ", 1))
#parse the blast output
with open ("UniVec/gde_blast.out") as blastin:
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
with open ("UniVec/gde_blast_ext.tsv", "w") as out:
    for i in blastex:
        out.write(i)
out.close
