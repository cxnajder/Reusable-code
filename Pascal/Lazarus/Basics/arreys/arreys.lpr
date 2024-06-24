program arreys;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes
  { you can add units after this };

var
  PiNums:array[1..8] of integer = (3, 1, 4, 1, 5, 9, 2, 6);
  i:integer;
begin

  for i := 1 to 8 do begin
    write(PiNums[i]);
    if i = 1 then
      write('.');
  end;

  writeln;
  readln;
end.

