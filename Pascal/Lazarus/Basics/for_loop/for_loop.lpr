program for_loop;

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

  for i := 1 to 5 do
  begin
    writeln(i);
  end;

  writeln('bazinga');

  for i := 5 downto 1 do
  begin
    writeln(i);
  end;

  writeln;
  writeln;

  writeln('Press enter to quit.');
  readln;

end.

