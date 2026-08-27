exec naluno (2023133420);

--Ex.3
select *
from autores;
EXEC SQLCHECK('FAJVLGCACJLCBHJ');

--Ex.4
select titulo
from livros
order by titulo;
EXEC SQLCHECK('FAHJXEKBGJQBCKP');

--Ex.5
select distinct genero
from livros
order by genero;
EXEC SQLCHECK('FAUFZVFCBUBGDUD');

--Ex.6
select titulo, genero, preco_tabela as "PRECO"
from livros
where preco_tabela > 30 
and preco_tabela < 40
order by preco_tabela;
EXEC SQLCHECK('FARJWDWDQYEYERU');
