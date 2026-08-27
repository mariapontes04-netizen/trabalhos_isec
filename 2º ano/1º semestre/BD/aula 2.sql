exec naluno(2023133420);

--Ex3
select genero, titulo, preco_tabela
from livros
where genero in ('Policial' , 'Aventura')
and preco_tabela < 60
order by titulo desc;
EXEC SQLCHECK('FBMAQMQCYJCTEIV');

--Ex4
select nome, idade, morada
from clientes
where idade between 30 and 55
and morada like '%Ovar'
order by nome asc;
EXEC SQLCHECK('FBWQIZVDBVCAFPC');

--Ex5
select distinct genero
from livros
where paginas < 400
and preco_tabela < 15
order by genero;
EXEC SQLCHECK('FBNUXWZEMHXVGPS');

--Ex6
select titulo, preco_tabela as preco
from livros
where genero like '%Informática'
and (preco_tabela * 0.8) < 20
order by preco_tabela asc;
EXEC SQLCHECK('FBOPVQKFFLSBHFT');

--Ex7
select ISBN, titulo, unidades_vendidas, genero, preco_tabela
from livros
where genero like '%Informática'
and round (preco_tabela) = 40
order by preco_tabela asc, unidades_vendidas desc;
EXEC SQLCHECK('FBGVUEEGBUQWIMR');

--Ex8
select distinct codigo_autor
from livros
where genero like '%Drama'
order by codigo_autor desc;
EXEC SQLCHECK('FBINSVUHXFWUJBS');

//Ex9
select titulo
from livros
where genero!='Policial'
order by preco_tabela;
EXEC SQLCHECK('FBKNEHPIHNVTKCF');

--Ex10
select titulo, ISBN, preco_tabela
from livros
where preco_tabela < 20
and not (genero in('Aventura','Policial'))
order by preco_tabela, codigo_livro;
EXEC SQLCHECK('FBXOJCQJDATPLKK');

--Ex11
select titulo, genero, paginas
from livros
where length(titulo) > 45
order by titulo;
EXEC SQLCHECK('FBGLEVDKEVHYMKI');

--Ex12
select nome, data_nascimento
from autores
where nome like '%o%' and nome like '%u%'
order by data_nascimento;
EXEC SQLCHECK('FBCFQVVLPDNKNAG');

--Ex13
select titulo, genero
from livros
where (titulo like 'O%' and titulo like '%st%')
or (titulo like 'R%' and titulo like '%eng%')
order by preco_tabela;
EXEC SQLCHECK('FBNNKNZMBKPHOBT');

--Ex14
select titulo, genero, preco_tabela
from livros
where (titulo like 'A%')
and not (genero in('Policial','Romance','Drama'))
order by titulo;
EXEC SQLCHECK('FBOTLBXNGHKSPCE');

--Ex15
select titulo, paginas as "Num de Paginas" , round(preco_tabela/paginas,2) as "Preco por página"
from  livros
where genero = 'Drama'
and paginas > 100
order by paginas;
EXEC SQLCHECK('FBVLIMIOEUBZQBM');

--Ex16
select codigo_livro, titulo, preco_tabela, round(unidades_vendidas/900) as "Media por loja"
from livros
where genero = 'Policial'
order by titulo;
EXEC SQLCHECK('FBKLVQAPRJNDRTD');

--Ex17
select 'O livro "' ||titulo|| '" com '  ||paginas|| ' paginas, foi escrito pelo autor com o codigo '|| codigo_autor as "Listagem paginas dos Livros"
from livros
where preco_tabela > 50 
and genero = 'Aventura'
order by titulo;
EXEC SQLCHECK('FBYCFSOQGLQYSFT');
