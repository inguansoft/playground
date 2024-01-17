
## Install in mac

``` bash
# install in mac
brew install mosquitto
# turn broker service on
brew services start mosquitto

# or just run it once:
/usr/local/opt/mosquitto/sbin/mosquitto -c /usr/local/etc/mosquitto/mosquitto.conf


# commands to send and receive from console:

mosquitto_sub -t topic/state
mosquitto_pub -t topic/state -m "Hello World"
```
## References
https://mosquitto.org/man/ : 
https://mosquitto.org/man/mosquitto_pub-1.html
https://mosquitto.org/man/mosquitto_sub-1.html
https://mosquitto.org/man/mosquitto_ctrl-1.html
