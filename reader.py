from Bio import AlignIO
import glob
import statistics
#####################################################################
#here the actual program begins, i'm storing the file names and
#annotations in their respective lists
#####################################################################
nomes=[]
sizes=[]
scores=[]
identities=[]
similarities=[]
gaps=[]
for file in glob.glob("*.align"):
    current=AlignIO.read (open(file), "emboss")
    size=current.get_alignment_length()
    nomes=nomes+[file]
    scores=scores+[current.annotations["score"]]
    identities=identities+[current.annotations["identity"]/size*100]
    similarities=similarities+[current.annotations["similarity"]/size*100]
    gaps=gaps+[current.annotations["gaps"]/size*100] #im storing the percentages
    sizes=sizes+[size]
#####################################################################
#now i have to take the elements of these lists and make decrescent
#sorted ones (by the scores)
#####################################################################
nomes2=[]
scores2=[]
identities2=[]
similarities2=[]
gaps2=[]
sizes2=[]
while(statistics.variance(scores)!=0):
    m=scores.index(max(scores))
    scores2=scores2+[scores[m]]
    nomes2=nomes2+[nomes[m]]
    identities2=identities2+[identities[m]]
    similarities2=similarities2+[similarities[m]]
    gaps2=gaps2+[gaps[m]]
    sizes2=sizes2+[sizes[m]]
    scores[m]=0
#####################################################################
#now it's time to print the results to a file
#####################################################################
out=open("resultado", "w")
out2=open("hist", "w")
length=len(scores2)
for i in range(0, length):
    towrite=(nomes2[i], ":\nsize: ", sizes2[i], "\nscore: ", scores2[i], "\nidentity: ",
        identities2[i], "%\nsimilarity: ", similarities2[i], "%\ngaps: ",
        gaps2[i], "%\n\n")
    towrite=''.join(map(str, towrite))
    out.write(towrite)
    towrite=(scores2[i], "\n")
    towrite=''.join(map(str, towrite))
    out2.write(towrite)
