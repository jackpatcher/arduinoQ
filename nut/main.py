from arduino.app_utils import *
from arduino.app_bricks.web_ui import WebUI
import time

# Start WebUI Brick
ui = WebUI()


def send_led_status():
    """
    Send the current LED state back to the webpage.
    """
    ui.send_message("led_status_update", {
        "led_is_on": led_is_on
    })


def SAMPLE_toggle_led(client, data):
    """
    This function runs when the HTML page sends:
    socket.emit("toggle_led", {})
    """
    global led_is_on

    # Change state: OFF -> ON, or ON -> OFF
    led_is_on = not led_is_on

    # Send command to Arduino sketch
    Bridge.call("set_led_state", led_is_on)

    # Tell webpage to update button color and text
    send_led_status()
    
# Bridge.call("servo", 0)

def servoPy() :
    Bridge.call("servo",90)
    
def servoPy090() :
    Bridge.call("servo",0)
    time.sleep(1)
    Bridge.call("servo",90)
    time.sleep(1)

def servoPyDeg(client, data) :
    deg = data.get("deg", 0)

    
    Bridge.call("servo",0)
    time.sleep(1)
    Bridge.call("servo",deg)
    
# servoPy090()


# Listen for message from HTML
ui.on_message("servoPyDeg", servoPyDeg)

# Start the app
App.run()