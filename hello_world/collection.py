import collections

def default_factory():
    return 'default value'

d = collections.defaultdict(default_factory, foo='bar')
e = {
    'a': 'this is A',
    'b': 'this is B'
}
array = [100, 234, 402]

print('d:', d)

print('foo =>', d['foo'])
print('bar =>', d['bar'])

print('e[a]=', e['a'], ' like this array[0]=', array[0])

print(str(array))

arrayb = reversed(array)

print(str(arrayb))

string_a = 'abcdefg'
string_b = reversed(string_a)
print("From: ", string_a , " reversed to: ", string_b )
