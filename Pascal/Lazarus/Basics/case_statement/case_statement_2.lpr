program case_statement_2;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes
  { you can add units after this };

var
   age : integer;
   phone_number : integer;

begin
  writeln('How old are you?');
  readln(age);

  case age of
  0..4 :begin
       writeln('Goo goo gaa gaa?');
       end;
  5..11 :begin
       writeln('Where the heck are your parents?!');
       end;
  12..17 :begin
       writeln('Sorry kid, you are too young to drink.');
       end;
  18..29 :begin
       writeln('Here! Have a drink.');
       writeln('What is your phone number?');
       readln(phone_number);
       writeln('*ring ring*');
       end;
  30..79 :begin
       writeln('The usual?');
       end;
  else begin
       writeln('Dear God... You should take a nap.');
       end;
  end;

  writeln;
  writeln;

  writeln('Press <Enter> to Quit');
  readln;
end.

