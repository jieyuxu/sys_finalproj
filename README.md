# HangASCIIman
By: Amy Xu, Mia O'Brien, Shaik Abiden

##HangASCIIman? That sounds brutal! What is it?!
HangASCIIman is the C remake of your favorite childhood game: Hangman! Instead of playing this game on a boring white or black or even smart (not so smart) board, play it in your very own terminal instead. 
*Note: It's recommended to play this with a friend. Or someone whose limbs you'd like to chop off in a socially acceptable and hidden way.*

##Ohhh...so how do you use it?
HangASCIIman runs without dependencies or external libraries so you do not need to install anything in advance.

1. Download or clone this github repository. If you've downloaded this repo, make sure to unzip.
2. If this is the first time ever playing this game, simply compile it by typing ```$make```
  * Psssttt....You can get rid of those ~ or .o files using ```$make clean```
3. Start a server by typing in ```./server```. 
4. Start a client by typing in ```./client```. 
5. Once you've gotten that all set up, select whether you'd like a dog or a man to hang. Then you will be prompted to enter a word into ```./server``` for your friend to start guessing.

*Note: Your downloaded/cloned repo should contain: ``` executioner.c (the hangman game) executioner.h client.c client.h selectserv.c networking.c networking.h makefile devlog.txt DESIGN.txt README.md```*

##Known Bugs
* the program accepts and allows non-letter ascii values
