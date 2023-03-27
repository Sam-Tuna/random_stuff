name_file = "names"
blastoutfile = "topdnr_anon.tsv"

#get names from file and save them in a dictionary
with open (name_file) as namin:
    names = namin.readlines()
namin.close
namesplit = {}
for i in names:
    x = i[1:].split(" ", 1)
    namesplit[x[0]] = x[1]
print ("namesplit")
#parse the blast output
with open (blastoutfile) as blastin:
    blast = blastin.readlines()
blastin.close
blastsplit = []
for i in blast:
    blastsplit.append(i.split("\t"))
print ("parsed blast")
#extend the names
blastex = []
for i in blastsplit:
#    print (i[0])
    if i[1] in namesplit:
#        print ("found key")
        j = namesplit[i[1]].rstrip()
        line = [i[0]]
        line.append("".join(j))
        for k in i[1:]:
            line.append(k)
        #line = ["".join(j), i[1]]
#        line[0] = line[0].replace("\n", "")
        blastex.append("\t".join(line))
    else:
    	continue
print (line)
#saves output
with open ("extended_names.tsv", "w") as out:
    for i in blastex:
        out.write(i)
out.close
