# Arduino Keypad
> simple implementation for a keypad

## Features
- four push buttons to enter a password
- one push button to confirm the input
- two leds (red and green) to display the state

## Use case

A typical use case for this implementation could be a hotel safe:

The customer enters a password with the four push buttons (represents digits 1-4). After the input he clicks the confirm button to validate the password. The led will switch from red to green for a valid password or stay red for an invalid input. After five seconds the led will switch back to red. It's not possible to enter a password while the keypad is in green mode.

It's not intended to use it in real world, because therefore encoding would be very important (the password is stored as plain text).

## License

See [License](LICENSE).