

# spot-electricity-display
A small arduino project for displaying spot electricity price
> This project uses API that has price in Finland 🇫🇮. It should be quite easy to switch API that is used.

### Electronics I used:
- Wemos Lolin D1 mini pro -board
- a battery case (used if the board isn't connected to a computer)

### How to set up/flash
Install all necessary libraries: 
- Adafruit Gfx
- Adafruit SSD1306

Crete a file named secret.h to the folder main and fill with this content. Replace placeholders with your wifi name and password.
```
#define SECRET_SSID = "your_wifi_name_here"
#define SECRET_PASSWORD = "your_wifi_password_here"
```
I used Arduino IDE for developing, so then I pressed "upload" to upload the code.

### Casing for electronics
I made this simple casing with tinkercad. I haven't tried to print it and I made it just for a reference how it could look like.
My idea with this project is that you could mount it on your wall and check easily current electricity price.

<img width="489" height="283" alt="Näyttökuva 2026-08-27 195707" src="https://github.com/user-attachments/assets/e0df6d7f-fc9f-46cf-a9ef-f697183e20a9" />

<img width="490" height="313" alt="Näyttökuva 2026-08-27 195733" src="https://github.com/user-attachments/assets/6d68999f-e3ea-44a4-8c87-cf50588453d5" />

> Tinkercad didn't have the exact board I have so I used one that was as close as possible.

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



