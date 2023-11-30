import string

s = 'The quick brown fox jumped over the lazy dog.'
print(string.capwords(s))

values = { 'var':'quiuboles' }
values_b = { 'va':'quiuboles' }

t = string.Template("""
Variable: $var
Escape: $$
Variable in text: ${var}iable
""")
t_b = string.Template("""
Variable: $var
Escape: $$
Variable in text: ${var}iable ${va}
""")
print ('TEMPLATE:', t.substitute(values))
print ('TEMPLATE:', t_b.safe_substitute(values_b))

s ="""
Variable:%(var)s
Escape:%%
Variable in text:%(var)siable
"""

print('INTERPOLATION:', s % values)






template_text = '''
  Delimiter : %%
  Replaced  : %with_underscore
  Ignored   : %notunderscored
'''

d = { 'with_underscore': 'replaced',
      'notunderscored': 'not replaced',
      }

class MyTemplate(string.Template):
    delimiter = '%'
    idpattern = '[a-z]+_[a-z]+'

t = MyTemplate(template_text)
print ('Modified ID pattern:')
print (t.safe_substitute(d))