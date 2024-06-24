program gotoxy_fun;

{$mode objfpc}{$H+}

uses
  crt,
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes
  { you can add units after this };

var
  Stop:integer;
  Matrix:integer;

begin
  Stop := 0;
  Matrix := 1;
  randomize;
  repeat
    gotoxy(random(119)+1, random(32)+1);
    if Matrix = 1 then
      writeln(random(9))
    else
      write(random(9))
  until Stop = 1;
end.

