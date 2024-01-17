curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
python3 get-pip.py
python3 -m pip install --upgrade pip

curl https://pyenv.run | bash
#in case: 
sudo apt install openssl libssl-dev

Edit your .bashrc by adding:
```
# Load pyenv automatically by appending
# the following to 
# ~/.bash_profile if it exists, otherwise ~/.profile (for login shells)
# and ~/.bashrc (for interactive shells) :

export PYENV_ROOT="$HOME/.pyenv"
[[ -d $PYENV_ROOT/bin ]] && export PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init -)"

# Load pyenv-virtualenv automatically by adding
# the following to ~/.bashrc:

eval "$(pyenv virtualenv-init -)"
```


Install python version you need:
```
pyenv install 3.8.18
pyenv versions

#create virtuallenvironment with pyenv

pyenv virtualenv 3.8.18 env_name
pyenv shell env_name
# here we are using python enviornment set
python --version
pip install -r requirements
```
