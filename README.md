# Tetris

Projet de première année codé en C à l'aide de la lib ncurse.

Projet réalisé à deux, ayant pour but de faire le jeu Tetris.

Gameplay :
  ./tetris [options]
  Options :         
      --help                Display this help
      -l --level={num}      Start Tetris at level num
      -kl --key-left={K}    Move tetrimino on LEFT with key K
      -kr --key-right={K}   Move tetrimino on RIGHT with key K
      -kt --key-turn={K}    Turn tetrimino with key K
      -kd --key-drop={K}    Set default DROP on key K
      -kq --key-quit={K}    Quit program when press key K
      -kp --key-pause={K}   Pause and restart game when press key K
      --map-size={row,col}  Set game size at row, col
      -w --without-next     Hide next tetrimino
      -d --debug            Debug mode
      
Touche de base :
    aller à gauche : flèche de gauche
    aller à droite : flèche de droite
    tourner : flèche du haut
    pauser le tetrimino : flèche du bas
    accelérer : f
    sauvegarde du tetrimino : h
    quitter : q
    pause : espace
