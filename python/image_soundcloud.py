import requests
from bs4 import BeautifulSoup
from PIL import Image
from io import BytesIO
import sys
import os

def get_html(url):
    try:
        r = requests.get(url)
    except:
        return
    #print(r.text)
    return r

def download_image(url):
    print(url)
    img = Image.open(BytesIO(get_html(url).content))
    #img.show()
    print(os.system("echo $PWD"))
    print(url.split('/')[3])
    img.save(url.split('/')[3])

def find_image(html):
    soup = BeautifulSoup(html, 'lxml')
    span = soup.find_all('img')
    for x in span:
        if (str(x).find("500", 0, len(str(x))) != -1):
            url = x.get('src')
            download_image(url)
def main():
    if (len(sys.argv) != 2):
        return 
    find_image(get_html(sys.argv[1]).text)

if __name__ == '__main__':
    main();
