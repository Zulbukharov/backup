import os

def main():
    username = ['newabl', 'demon', 'suslik']
    firstname = ['freddie', 'hel', 'gde']
    lastname = ['dredd', 'yeah', 'dengi']
    foo = len(username)
    for x in range(0, foo):
        request = 'http http://127.0.0.1:5000/users username={0} firstname={1} lastname={2}'.format(username[x], firstname[x], lastname[x])
        print(request)
        os.system(request)


if __name__ == '__main__':
    main()
