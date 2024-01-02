import argparse
import os
import requests
from selenium import webdriver
from selenium.webdriver.firefox.options import Options as FirefoxOptions
from selenium.webdriver.firefox.service import Service as FirefoxService
from bs4 import BeautifulSoup as bs
from urllib.parse import urljoin, urlparse
ALLOWED_EXTENSIONS = {".jpg", ".jpeg", ".png", ".gif", ".bmp"}

parser = argparse.ArgumentParser(
    prog='spyder',
    description='Web Spider for Image Extraction')
parser.add_argument("URL", help='URL of the website')
parser.add_argument("-r", action='store_true', help='Recursively download images')
parser.add_argument("-l", type=int, default=5, help='Maximum depth level for recursive download')
parser.add_argument("-p", default='./data/', help='Path to save doawnloaded files')
args = parser.parse_args()

def main():    
    if not os.path.exists(args.p):
        os.makedirs(args.p)
    extract_images(args.URL)


def extract_images(url, depth=0):
    if args.l < depth:
        return

    firefox_options = FirefoxOptions()
    firefox_options.set_preference("browser.privatebrowsing.autostart", True)
    firefox_service = webdriver.FirefoxService(executable_path="/home/bolvic/Desktop/MyGitHub/42/piscine_Cybersecurity/arachnida/spider/geckodriver")
 
    driver = webdriver.Firefox(service=firefox_service, options=firefox_options)
    driver.get(url)
    content = driver.page_source
    driver.quit()
    
    soup = bs(content, "html.parser")
    img_tags = soup.find_all("img")
    
    for img_tag in img_tags:
        if "src" in img_tag.attrs:
            img_src = img_tag["src"]
            img_url = urljoin(str(url), str(img_src))
            filename = os.path.join(args.p, os.path.basename(urlparse(img_url).path))
            download_image(img_url, filename)
    if args.r:
        links = soup.find_all("a", href=True)
        for link in links:
            link_url = urljoin(url, link["href"])
            if link_url.startswith(args.URL):
                extract_images(link_url, depth + 1)

def download_image(url, output_path):
    response = requests.get(url)
    if response.status_code == 200:
        _, ext = os.path.splitext(urlparse(url).path)
        if ext.lower() in ALLOWED_EXTENSIONS:
            with open(output_path, "wb") as img_file:
                img_file.write(response.content)

if __name__ == "__main__":
    main()
