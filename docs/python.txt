curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
python3 get-pip.py
python3 -m pip install --upgrade pip

curl https://pyenv.run | bash
#in case: 
sudo apt install openssl libssl-dev

#edit your .bashrc

coming up


#install python version you need:
pyenv install 3.8.18
pyenv versions

#create virtuallenvironment with pyenv

pyenv virtualenv 3.8.18 env_name
pyenv shell env_name
# here we are using python enviornment set
python --version
pip install -r requirements

