with open ("contig_hits.txt") as file:
	lines = file.readlines()
fim = []
for line in lines[1:]:
	splitlines = line.split(" ")
	if (int(splitlines[1])>100000):
		fim.append(line)

with open ("filtered_hits.txt", "w") as out:
	for i in fim:
		out.write(i)
out.close
