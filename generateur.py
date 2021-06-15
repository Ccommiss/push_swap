import random

# using list comprehension + randrange()
# to generate random number list
res = random.sample(range(0,500), 500)
clean = str(res)
clean = clean.replace(",", "")
clean = clean.replace("[", "")
clean = clean.replace("]", "")

# printing result

print (clean)
