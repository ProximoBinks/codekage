from selenium import webdriver
import time

# Initialize the Chrome driver
driver = webdriver.Chrome()  # Make sure chromedriver is in your PATH or specify the path

# Maximize the window and open a website
driver.maximize_window()
driver.get("http://127.0.0.1:3000/index.html")
time.sleep(2)  # Wait for a moment to see the maximized window

# Get the initial position and size
initial_pos = driver.get_window_position()
initial_size = driver.get_window_size()

# Function to resize and reposition window
def resize_and_reposition(driver, target_width, step, delay):
    current_width = initial_size['width']
    while current_width != target_width:
        new_width = max(target_width, current_width - step)
        new_x = initial_pos['x'] + (current_width - new_width) // 2
        driver.set_window_size(new_width, initial_size['height'])
        driver.set_window_position(new_x, initial_pos['y'])
        current_width = new_width
        time.sleep(delay)

# Parameters for resizing
target_width = 800   # target width to resize to
step = 10            # change in width each step
delay = 0.05         # delay (in seconds) between each resize

# Resize and reposition the window
resize_and_reposition(driver, target_width, step, delay)

# Close the browser after some time
time.sleep(5)
driver.quit()
