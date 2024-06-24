program val_function;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes
  { you can add units after this };
var
  UserInput:string;
  InputNumber:real;
  InputError:integer;

begin
  repeat
    write('Enter A Valid Number: ');
    readln(UserInput);
    val(UserInput, InputNumber, InputError);
    if InputError <> 0 then
      writeln('Invalid Input: ', UserInput);
  until InputError = 0;

  writeln('Valid Number: ', InputNumber:0:2);
  readln;

end.

