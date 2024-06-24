program reapeat_until_loop;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes
  { you can add units after this };

var
  i : integer;

begin

  i := 0;

  repeat
    writeln('i = ', i);
    i := i + 1;
  until i = 10;

  writeln('loop ended');
  writeln('i = ', i);

  writeln;
  writeln;

  writeln('Press enter to quit.');
  readln;

end.

