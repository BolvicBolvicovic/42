import argparse
import os
import requests
from urllib.parse import urljoin, urlparse
from html.parser import HTMLParser

ALLOWED_EXTENSIONS = {".jpg", ".jpeg", ".png", ".gif", ".bmp"}

class ImageParser(HTMLParser):
    def __init__(self, base_url, depth):
        super().__init__()
        self.base_url = base_url
        self.depth = depth
        self.image_urls = []
        self.anchor_list = []

    def handle_starttag(self, tag, attrs):
        if tag == "img":
            for attr, value in attrs:
                if attr == "src":
                    img_url = urljoin(self.base_url, value)
                    self.image_urls.append(img_url)
        elif tag == "a":
            self.anchor_list.append((tag, dict(attrs)))

def extract_images(url, depth=0):
    if args.l < depth:
        return

    response = requests.get(url)
    if response.status_code == 200:
        parser = ImageParser(url, depth)
        parser.feed(response.text)
        for img_url in parser.image_urls:
            filename = os.path.join(args.p, os.path.basename(urlparse(img_url).path))
            download_image(img_url, filename)

        if args.r:
            parser.feed(response.text)
            links = [tag[1] for tag in parser.anchor_list if tag[0] == "a" and "href" in tag[1]]
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

def main():
    if not os.path.exists(args.p):
        os.makedirs(args.p)
    extract_images(args.URL)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog='spyder',
        description='Web Spider for Image Extraction')
    parser.add_argument("URL", help='URL of the website')
    parser.add_argument("-r", action='store_true', help='Recursively download images')
    parser.add_argument("-l", type=int, default=5, help='Maximum depth level for recursive download')
    parser.add_argument("-p", default='./data/', help='Path to save downloaded files')
    args = parser.parse_args()
    main()
