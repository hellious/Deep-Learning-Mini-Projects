# writng a crawler which will parse all the anchor tage and return 
import requests as rq
from bs4 import BeautifulSoup

def main():
    # give the url to ind all href
    url = "https://www.google.com"
    res = rq.get(url)
    page = BeautifulSoup(res.content,"html")
    all_href = page.findAll("a")
    return set(all_href)    
    
if __name__ = "__main__":
    main()