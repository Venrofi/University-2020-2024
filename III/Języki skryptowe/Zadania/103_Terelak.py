from html.parser import HTMLParser
import urllib.request

class LinkScrape(HTMLParser):
    links = []

    def handle_starttag(self, tag, attrs):
        if tag == "a":
            for attr in attrs:
                if attr[0] == "href":
                    link = attr[1]
                    if link.find("http") >= 0:
                        self.links.append(link)

def main():
    url = "https://docs.python.org/3/library/html.parser.html"
    request_object = urllib.request.Request(url)
    page_object = urllib.request.urlopen(request_object)
    link_parser = LinkScrape()
    link_parser.feed(page_object.read().decode("utf-8"))
    dct = {i: link_parser.links.count(i) for i in link_parser.links}

    for i in link_parser.links:
        print("{} jest unikalny: {}".format(i, dct[i] < 2))

main()