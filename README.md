# spot-electricity-display
A small arduino project for displaying spot electricity price

### Electronics I used:
- Wemos Lolin D1 mini pro board
- a battery case

### How to set up/flash
Install all necessary libraries: 

Crete a file named secret.h and fill with this content. Replace placeholders with your wifi name and password.
```
#define SECRET_SSID = "your_wifi_name_here"
#define SECRET_PASSWORD = "your_wifi_password_here"
```
I used Arduino IDE for developing, so then I pressed "upload" to upload the code.

### References
API: https://api.spot-hinta.fi/swagger/ui
