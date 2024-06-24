program guess_game;

{$mode objfpc}{$H+}

uses
  crt,
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes
  { you can add units after this };

var
GameMode:string;
UserInput:string;
answer:integer;
guess:integer;
valError:integer;
guessCounter:integer;

begin
  repeat
    guessCounter := 0;
    repeat
      clrscr;
      writeln('Select a game mode:');
      writeln;
      writeln('1) 1 - 10');
      writeln('2) 1 - 100');
      writeln('3) 1 - 1000');
      writeln('4) 1 - custom');
      writeln;
      write('Enter selection: ');
      readln(GameMode);

    until
      (GameMode = '1') or
      (GameMode = '2') or
      (GameMode = '3') or
      (GameMode = '4');

      clrscr;
      randomize;

      case GameMode of
        '1':begin
          answer := random(10)+1;
          writeln('Guess 1 - 10');
        end;
        '2':begin
          answer := random(100)+1;
          writeln('Guess 1 - 100');
        end;
        '3':begin
          answer := random(1000)+1;
          writeln('Guess 1 - 1000');
        end;
        '4':begin
          repeat
            write('Enter custom end range: ');
            readln(UserInput);
            val(UserInput, guess, valError);
            if(valError <> 0) then
              writeln('Invalid range');
          until (valError = 0) and (guess > 1);

          answer := random(guess)+1;
          writeln('Guess 1 - ', guess);
        end;
      end;

      writeln;
      repeat
        repeat
          write('Try ', guessCounter+1 ,' - Write your answer: ');
          readln(UserInput);
          val(UserInput, guess, valError);
          if valError <> 0 then
            writeln('Invalid input');
        until valError = 0;
        guessCounter := guessCounter + 1;
        if guess < answer then
          writeln('higher')
        else if guess > answer then
          writeln('lower')
      until guess = answer;

      writeln('You guessed the number ', answer,' in ', guessCounter, ' trys');
      writeln;
      writeln('Press Q to Quit.');
      writeln('Press anything else to play again.');
      readln(GameMode);
    until (GameMode = 'q') or (GameMode = 'Q');
    writeln;
    writeln('Press <ENTER> to close console');
    readln;

end.

