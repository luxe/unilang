#!/usr/bin/env python
import requests

# Get the HTML content from the webpage.
text = requests.get("https://www.cs.columbia.edu/~hgs/audio/harvard.html").text

# Remove these HTML tags so the content is easier to parse.
html_tags = ["body","h2","ol","li"]
for tag in html_tags:
	text = text.replace("<" + tag + ">","")
	text = text.replace("</" + tag + ">","")

# Split each line into its own element.
split = text.split('\n')
split = [i for i in split if i]

# Lists contain sentences.
# We will parse out a list of lists.
lists = []
sentences = []
at_lists = False
for s in split:
	if s.startswith("List"):
                at_lists = True
		if sentences:
			lists.append(sentences)
		sentences = []
		continue;
	if at_lists:
		sentences.append(s)
if sentences:
	lists.append(sentences)



# Now we have a list of l[x][y]
# where x indexes the group of sentences
# and y are the individual sentences.
# To verify, the website shows there are 72 lists.
assert len(lists) == 72

#Get all the words that end in "ing".
ing_words = []
for l in lists:
	for sentence in l:

		# Remove puncuation and extract words.
		sentence = sentence.replace(".","")
		words = sentence.split(' ')

		# Store words that end in "ing"
		for word in words:
			if word.endswith("ing"):
				ing_words.append(word)


# There appears to be 52 words that end in "ing".
assert len(ing_words) == 52


# Count the occurrences of each word.
occurrences = {}
[ occurrences.update( {i:occurrences.get(i, 0)+1} ) for i in ing_words ]
print(occurrences)
