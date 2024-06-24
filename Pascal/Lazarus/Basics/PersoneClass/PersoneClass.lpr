program PersonExample;

{$APPTYPE CONSOLE}

type
  TPerson = class
    private
      FFirstName: string;
      FLastName: string;
      FAge: Integer;

    public
      constructor Create;
      constructor CreateWithNames(const FirstName, LastName: string);
      procedure SetName(const FirstName, LastName: string);
      procedure SetAge(Age: Integer);
      function GetFullName: string;
      function GetAge: Integer;
  end;

constructor TPerson.Create;
begin
  FFirstName := '';
  FLastName := '';
  FAge := 0;
end;

constructor TPerson.CreateWithNames(const FirstName, LastName: string);
begin
  Create;
  SetName(FirstName, LastName);
end;

procedure TPerson.SetName(const FirstName, LastName: string);
begin
  FFirstName := FirstName;
  FLastName := LastName;
end;

procedure TPerson.SetAge(Age: Integer);
begin
  FAge := Age;
end;

function TPerson.GetFullName: string;
begin
  Result := FFirstName + ' ' + FLastName;
end;

function TPerson.GetAge: Integer;
begin
  Result := FAge;
end;

var
  person: TPerson;
  firstName, lastName: string;
  age: Integer;
  ageInput: string;
  ageError: Integer;

begin

  Write('Enter first name: ');
  Readln(firstName);

  Write('Enter last name: ');
  Readln(lastName);

  person := TPerson.CreateWithNames(firstName, lastName);

  Write('Enter age: ');

  repeat

    Readln(ageInput);
    val(ageInput, age, ageError);

    if ageError <> 0 then
      Write('Enter valid age: ');
      
    if (age < 0) or (age > 122) then
      Writeln('Age must be in range 0 - 122: ');

  until (ageError = 0) and (age >= 0) and (age <= 122);

  person.SetAge(age);

  Writeln('Person information:');
  Writeln('Name: ', person.GetFullName);
  Writeln('Age: ', person.GetAge);

  person.Free;

  readln;
end.

