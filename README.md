# ZORK - Simple Game Assignment
## 1. Description
It is a C ++ programming exam with Visual Studio which consists on a single exercise where a small conversational game is implemented, starting from a base code. The purpose of this test is to prove that the programming level is appropriate to follow the course. 

## 2. Authors
The main author is me, Javier Castaño, whose intention is to pass the test and be part of the Advanced Programming for AAA Video Games master's degree at the UPC School.

## 3. How to play
It follows the gameplay style from the original Zork!, with little few changes. It works with the following commands:

- `<direction> | go <direction>: Move to another room (examples: 'go north', 'n').`
- `look: Examine the actual room and its entities.`
- `take <object>/get <object>: Grab an object.`
- `open <object>: Open an object (if possible).`
- `inventory: Check items you carry.`
- `unlock <dirección>: Unlock a door at the corresponding direction (hint: you probably need a key).`
- `quit: Exit the game.`
- `drop: Drop an object.`
- `put <object> in <object>: Put an object inside another one (if possible).`
- `read <object>: Read an object like a note or a letter.`
- `move <object>: Move an object which is acting as an obstacle.`
- `kill <creature> with <item>: Attack a creature with an object in your possession.`

NOTE: You CAN'T take items that are inside another item that you already have in your inventory. For example, you CAN'T take the key inside the book if the book is already in your inventory. However, you can put it back in the book even if it is already in your inventory. I just had no time to do the rest :(

## 4. Objective
Your objective is to move through the rooms, unlocking doors, taking objects and even defeating enemies until you get to the end.

Here is a map to guide yourself during the game:

![alt text](https://github.com/javiercasman/Zork/blob/main/Zork/map.png?raw=true)

To end the game, you have to find the Amulet at the Gallery, then use it in the Garden. However, there is a hostile Troll guarding it, lurking around the Cellar and its surroundings! You must kill him (strongly recommended doing it with the Sword found at the Entry) to get the key that will you allow to escape from the house.

## 5. Unique features
I added some extra features that were not included on the main ones at the PDF, you could notice some of them on the commands list. These are:
- Moveable and readable items
- Combat
- A creature that walks around (it has a little chance to move through the Gallery - Cellar - Studio rooms)
- Exits that you can open with keys

Also, I though on adding other ones, like the chance to save the game and restore it, or restart it, also add the requirement for some rooms to have a lamp on, otherwise you will be killed by a Grue (like in the original Zork!), but I had no time to do it, I wanted to be sure that the things that I added where well structured and implemented. However, I think it could be have done better, because after all I still think I have been too ambitious and underestimated the 'little' time I had to do all those things.

## 6. Challenge and learning
As I just described, I think I might have been too ambitious with this project. It has been quite a while since I did not put myself against a programming project that required a certain well-designed class structure like this one, so at the beginning I had some struggle to move on and decide where to start.

Also, I don't want to use this as an excuse, but I had the """"bad"""" luck that, last weekend, was my birthday (yay!), and my friends prepared a surprise party for me, so let's say that it took me quite a bit of my time. To be honest, I should have seen it coming, hahah.

Anyway, although the difficulties I had during this week, and fighting against the clock and my perfectionism, I think I got a pretty decent result. Surely, it can be improved, in fact, during the development, I noticed myself that some of the ideas I had at the beginning weren't as good as I thought they were (you can see some of them at the `ideas.txt` if you want, also in the comments at the own code).

However, I am very proud of what I have done, and even I learnt some things and remembered lot of concepts that I previously knew at college, but that I forgot. Also, I have known Zork!, which is a very interesting concept of a videogame that I have never seen, and made me realize that it settled (or inspired from other games that settled) a lot of concepts that nowadays we see in tons of videogames.

## 7. Repository
This project is uploaded at my GitHub profile on the following [link](https://github.com/javiercasman/Zork/tree/main)

## 8. License
This project is licensed under the MIT License. This means you are free to use, modify, and distribute the code as long as you include the original license notice.

You can read the full license text in the [LICENSE](LICENSE) file in this repository or at the following link:

[MIT License - Open Source Initiative](https://opensource.org/license/mit)