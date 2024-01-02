import argparse
import os
import datetime

ALLOWED_EXTENSIONS = {".jpg", ".jpeg", ".png", ".gif", ".bmp"}

def get_creation_date(file_path):
    try:
        creation_time = os.path.getctime(file_path)
        creation_date = datetime.datetime.fromtimestamp(creation_time)

        return creation_date.strftime("%Y-%m-%d %H:%M:%S")

    except Exception as e:
        print(f"Error getting creation date for {file_path}: {str(e)}")
        return "N/A"


def display_metadata(file_path):
    try:
        print(f"File: {file_path}")
        print(f"Creation Date: {get_creation_date(file_path)}")

    except Exception as e:
        print(f"Error processing {file_path}: {str(e)}")

def main():
    parser = argparse.ArgumentParser(
        prog='scorpion',
        description='Scorpion for Image Parsing')
    parser.add_argument("FILE", nargs="+", help='File Name')
    args = parser.parse_args()
    for file_path in args.FILE:
        display_metadata(file_path)
        print("\n" + "-" * 40 + "\n")

if __name__ == "__main__":
    main()
