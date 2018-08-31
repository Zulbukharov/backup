import sys
import os

def main():
    if (len(sys.argv) < 3):
        print('Usage: python request.py <method || 0> <section || 0> <data=value>')
        return (0)
    method = sys.argv[1]
    url = 'http'
    if (method != '0'):
        url += ' ' + method + ' http://127.0.0.1:5000/'
    else:
        url += " http://127.0.0.1:5000/"
    section = sys.argv[2]
    if (section != '0'):
        url += section
        print(url)
    for i in range (3, len(sys.argv)):
        print(sys.argv[i])
        url += " " + sys.argv[i]
    os.system(url)
    print(url)

if __name__ == '__main__':
    main()
