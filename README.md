

# spot-electricity-display
A small arduino project for displaying spot electricity price ⚡
> This project uses API that has spot electricity price in Finland 🇫🇮. It should be quite easy to switch API that being is used.

#### With spot-electricity-display you don't need to open an electricity price app to check current spot price.

### Spot electricty explained (short version)
Instead of a default electricity price the price changes every 1hr or 15 min. 
The price depends, for example, on the amount of electricity available. For instance, more electricity can be generated in windy weather.
It can save some money if electricity use can be timed on a cheap hour.

## What does the code do?
 - Connects to the given wifi network 
 - When first powered, it takes a while to connect to wifi and fetch data (~15s)
 - Then it automatically gets current electricity price every 15 min when a new price interval starts.

### Electronics I used:
- Wemos Lolin D1 mini pro -board [link](https://www.wemos.cc/en/latest/d1/d1_mini_pro.html)
- OLED Screen [link](https://www.wemos.cc/en/latest/d1_mini_shield/oled_0_66.html)
- a battery case (used if the board isn't connected to a computer)

### How to set up/flash
Install all necessary libraries: 
- Adafruit Gfx
- Adafruit SSD1306


Crete a file named secret.h to the folder main and fill with this content. Replace placeholders with your wifi name and password 🛜.
```
#define SECRET_SSID = "your_wifi_name_here"
#define SECRET_PASSWORD = "your_wifi_password_here"
```
I used Arduino IDE for developing, so then I pressed "upload" to upload the code.

### Common reasons why it doesn't work
- No wifi name and password set
- The wifi isn't turned on (if you're using your phones hot spot you might need to turn it on every time)

#### Wiring
- No external components other than the screen, just battery connected. The OLED Screen was already connected to the board with pin headers when I started. 
  
### Casing for electronics
I made this simple casing with tinkercad. I haven't tried to print it and I made it just for a reference how it could look like.
My idea with this project is that you could mount it on your wall and check easily current electricity price.

<img width="489" height="283" alt="Näyttökuva 2026-08-27 195707" src="https://github.com/user-attachments/assets/e0df6d7f-fc9f-46cf-a9ef-f697183e20a9" />

<img width="490" height="313" alt="Näyttökuva 2026-08-27 195733" src="https://github.com/user-attachments/assets/6d68999f-e3ea-44a4-8c87-cf50588453d5" />

> Tinkercad didn't have the exact board I have so I used one that was as close as possible.

<img width="531" height="487" alt="image" src="https://github.com/user-attachments/assets/93c97128-426a-477c-b180-d54355844bc5" />

How it could look like in real life. Perspectives failed but you get the idea of the size and where to put it.

### Demo
Data when I filmed this:
```
{
  "Rank": 62,
  "DateTime": "2026-08-28T18:45:00+03:00",
  "PriceNoTax": 0.04403,
  "PriceWithTax": 0.05526
}
```
https://github.com/user-attachments/assets/52bd172b-c478-4eaf-847e-5dd602a25172


### References
API: https://api.spot-hinta.fi/swagger/ui



