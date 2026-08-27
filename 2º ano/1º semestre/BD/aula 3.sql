exec naluno(2023133420);

--Ex3
select titulo, preco_tabela
from livros 
where genero like '%Informática'
and codigo_autor = (select codigo_autor from autores where nome = 'Marta Fonseca')
order by titulo;
EXEC SQLCHECK('FCCZPAOCIGQRFWJ');

--Ex4
select L.titulo, A.morada
from livros L
join autores A
on L.codigo_autor = A.codigo_autor
where L.genero LIKE '%Aventura'
and A.morada LIKE '%Portalegre'
order by L.titulo;
EXEC SQLCHECK('FCDOVORDVBDYGYC');

--Ex5
select distinct A.nome, To_Char(A.data_nascimento, 'YYYY')as Ano_De_Nascimento
from autores A, livros L
where A.genero_preferido = L.genero
and L.codigo_autor = A.codigo_autor
order by Ano_De_Nascimento, A.nome;
EXEC SQLCHECK('FCZNODMEIXEJHZJ');

--Ex6
select L.titulo, L.genero, L.preco_tabela 
from livros L, clientes C, vendas V, contem Co
where C.codigo_cliente = V.codigo_cliente
and V.codigo_venda = Co.codigo_venda
and Co.codigo_livro = l.codigo_livro
and C.morada like '%Lisboa'
order by titulo;
EXEC SQLCHECK('FCRBLZVFBDUWIVB');

--Ex7
select distinct nome as "Nome completo", floor(months_between(SYSDATE, data_nascimento)/12) as Idade
from autores
where lower (nome) like '%ramos'
order by nome;
EXEC SQLCHECK('FCUSADAGIOXZJUN');

--Ex8
select A.nome, A.genero_preferido, L.titulo, L.genero, L.preco_tabela
from autores A, livros L
where A.codigo_autor = L.codigo_autor
and L.preco_tabela > 70
and L.genero != A.genero_preferido
order by A.nome, L.titulo;
EXEC SQLCHECK('FCMCECYHVMWOKFI');

--Ex9
select titulo, preco_tabela, unidades_vendidas, round(unidades_vendidas * preco_tabela * 0.05, 2) as "Rendeu"
from livros
order by titulo;
EXEC SQLCHECK('FCFFKUCICKZULQR');

--Ex10
select titulo,
    floor(preco_tabela * unidades_vendidas * 0.30) as "Rendimento"
from livros 
where (preco_tabela * unidades_vendidas * 0.30) > 12000
order by genero, preco_tabela;
EXEC SQLCHECK('FCIIBDCJGDETMIH');

--Ex11
select titulo, 
    round (preco_tabela / paginas, 2) as "Custo página",    
    ceil (preco_tabela / paginas) as "Custo pág.(sup)",
    floor (preco_tabela / paginas) as "Custo pág.(inf)"
from livros 
where paginas between 200 and 500
order by titulo;
EXEC SQLCHECK('FCNKGLCKMQQWNEE');

--Ex12
select upper(titulo) as "Titulo (em maisculas)",
    lower(titulo)as "Titulo (em minusculas)",
    initcap(lower(titulo)) as "Titulo (1a letra maiúscula)"
from livros 
order by titulo;
EXEC SQLCHECK('FCKTZWWLBVZOOAW');

--Ex13
select titulo as "Titulo", paginas, preco_tabela
from livros 
where lower (genero) like '%drama'
and paginas > 200
order by paginas;
EXEC SQLCHECK('FCLGQSUMWLNVPWM');

--Ex14
select nome as "Nome completo",
    SUBSTR(nome, 1, INSTR(nome, ' ') - 1) as "Primeiro Nome",
    SUBSTR(nome, INSTR(nome, ' ', -1) + 1) as "Ultimo Nome"
from autores
where months_between(SYSDATE, data_nascimento) / 12 > 35
order by data_nascimento;
EXEC SQLCHECK('FCOTEJMNNRLTQKF');

--Ex15
select upper(L.titulo) as "Titulo (em maisculas)",
    lower(L.genero) as "genero (min.)",
    initcap(lower(A.nome)) as "Nome Autor (1a letra)"
from livros L, editoras E, autores A
where L.paginas > 100
and L.codigo_editora = E.codigo_editora
and E.nome like '%Dom Quixote'
and L.codigo_autor = A.codigo_autor
order by L.titulo desc;
EXEC SQLCHECK('FCWYJKCOZCBERIZ');

--Ex16
select titulo, genero
from livros
where length (titulo) > 30
and lower (titulo) like '%power%'
order by titulo;
EXEC SQLCHECK('FCSEATCPOBCXSOT');

--Ex17
select titulo, 
    preco_tabela as "PRECO", 
    round(preco_tabela * 1.06, 1) as "PRECO_COM_AUMENTO"
from livros
where genero like '%Drama' 
and (preco_tabela * 0.06) > 2
order by titulo;
EXEC SQLCHECK('FCRFKISQBNSNTCC');
