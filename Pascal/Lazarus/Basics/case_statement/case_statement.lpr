program case_statement;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes
  { you can add units after this };

var
   first_name : string;
   last_name : string;
   age_group : char;
   phone_number : integer;

begin
  write('Enter your first name: ');
  readln(first_name);

  write('Enter last name: ');
  readln(last_name);

  writeln('Hello ', first_name, ' ', last_name);

  writeln('Pick your age group: ');
  writeln('A) 18 +');
  writeln('B) 14- 17');
  writeln('C) 5 - 13');
  writeln('D) 0 - 5');
  readln(age_group);

  case age_group of
  'A', 'a' :begin
       writeln('Here! Have a drink.');
       writeln('What is your phone number?');
       readln(phone_number);
       writeln('*ring ring*');
       end;
  'B', 'b' :begin
       writeln('Sorry kid, you are too young to drink.');
       end;
  'C', 'c' :begin
       writeln('Where the heck are your parents?!');
       end;
  'D', 'd' :begin
       writeln('Goo goo gaa gaa?');
       end;
  else begin
       writeln('What the heck...?');
       end;
  end;

  writeln;
  writeln;

  writeln('Press <Enter> to Quit');
  readln;
end.

