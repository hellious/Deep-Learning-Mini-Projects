import re
import operator

test_cases = int(raw_input())
document_c = []
document_f = []
visited = []
corpusFruit = {}
corpusCompany = {}
stopwords = ["a","the","an","you","your","i","do","not","in","many","was","were","of","between","is","are","to","for","other",
             "by","own","or","their","there","after","it","from","with","due","since","into","since",".","?","'","!","not","nt"];
rx = re.compile('\W+')
with open('apple-fruit.txt','r') as fruit:
    for line in fruit:
        line = rx.sub(" ",line).strip()
        line = line.split(" ")
        visited = []
        for word in line:
            if re.search("pple",word) is None:
                word = word.lower()
            if word not in stopwords:
                if word not in visited:
                    document_f.append(word)
                    visited.append(word)
                if word in corpusFruit:
                    corpusFruit[word] +=1
                else:
                    corpusFruit[word] = 1

with open('apple-computers.txt','r') as company:
    for line in company:
        line = rx.sub(" ",line).strip()
        line = line.split(" ")
        visited = []
        for word in line:
            if re.search("pple",word) is None:
                word = word.lower()
            if word not in stopwords:
                if word not in visited:
                    document_c.append(word)
                    visited.append(word)
                if word not in corpusCompany:
                    corpusCompany[word] = 1
                else:
                    corpusCompany[word] += 1


sorted_f = sorted(corpusFruit.iteritems(), key=operator.itemgetter(1))    

#remove frequent and common words    
for word in sorted_f[:400]:
    if word in corpusCompany:
        del corpusFruit[word]
        del corpusCompany[word]
        

for i in range(test_cases):
    line = raw_input()
    if "apples" in line or "apple" in line:
        print 'fruit' 
        continue
        
    line = rx.sub(" ",line).strip()
    line = line.split(" ")
    score_c,score_f = 0,0

    for word in line:
        if word in corpusFruit:
            score_f = score_f + 1
        if word in corpusCompany:
            score_c =  score_c + 1

    if score_c > score_f:
        print 'computer-company'
    else:
        print 'fruit' 




