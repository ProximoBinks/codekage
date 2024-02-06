import pyautogui
import time

def smooth_scroll_for_duration(duration, step_size):
    start_time = time.time()  # Record the start time
    while time.time() - start_time < duration:  # Continue until the duration is reached
        pyautogui.scroll(-step_size)  # Negative for scrolling down
        time.sleep(0.02)  # Short sleep for smooth scrolling

# Set your duration and step size here
duration = 600  # Duration in seconds for which you want to scroll
step_size = 1  # Smaller step for smoother scrolling

print("Starting smooth scroll for 60 seconds...")
smooth_scroll_for_duration(duration, step_size)
print("60 seconds of smooth scrolling completed.")
