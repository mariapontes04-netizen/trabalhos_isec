exec naluno(2023133420);

--Ex3
select L.titulo, A.nome, L.genero, L.preco_tabela
from livros L, autores A
where a.codigo_autor = l.codigo_autor
and a.nome like '%Valente'
and l.data_edicao between '2020-01-01' and '2020-12-31'
order by l.data_edicao, l.preco_tabela;
EXEC SQLCHECK('FDMDICKCWLKDGKR');

--Ex4
select TO_CHAR(SYSDATE, 'DDTH, Month, YYYY') as "Data Atual",
        TO_CHAR(SYSDATE, 'HH24:MI:SS AM') as "Hora Atual"
from DUAL;
EXEC SQLCHECK('FDAQRZBDABULHYX');

--Ex5
select To_Char(L.data_edicao, 'DD Mon YYYY')as Data_Edicao, L.titulo as "Titulo", A.nome, L.preco_tabela as "Preço"
from livros L, autores A 
where l.codigo_autor = a.codigo_autor
and l.data_edicao >= sysdate - 80
order by l.data_edicao;
EXEC SQLCHECK('FDWLWHTEXWQAIVG');

--Ex6
select l.titulo, l.preco_tabela
from livros L, contem Co, vendas V, clientes C
where l.genero like '%Informática'
and l.codigo_livro = co.codigo_livro
and co.codigo_venda = v.codigo_venda
and v.data_venda between TO_DATE('12-05-2022', 'DD-MM-YYYY') and TO_DATE('12-06-2024', 'DD-MM-YYYY')
and c.codigo_cliente = v.codigo_cliente
and c.morada like '%Odivelas'
order by l.titulo;
EXEC SQLCHECK('FDKWHQSFWQZCJIY');

--Ex7
select l.titulo, To_Char(l.data_edicao, 'YYYY-MM') as Ano_Mes
from livros L, contem Co, vendas V
where lower (l.genero) like '%informática'
and l.codigo_livro = co.codigo_livro
and co.codigo_venda = v.codigo_venda
and To_Char(v.data_venda, 'YYYY-MM') = To_Char(l.data_edicao, 'YYYY-MM')
order by To_Char(l.data_edicao, 'YYYY-MM');
EXEC SQLCHECK('FDZHRUYGKCFZKUQ');

--Ex8
select distinct a.nome, a.genero_preferido
from autores A, livros L
where a.codigo_autor = l.codigo_autor
and lower (l.genero) like '%fição'
and l.paginas<100
and (l.data_edicao between TO_DATE('21-06-2022', 'DD-MM-YYYY') and TO_DATE('21-09-2022', 'DD-MM-YYYY')
or l.data_edicao between TO_DATE('22-09-2022', 'DD-MM-YYYY') and TO_DATE('21-12-2022', 'DD-MM-YYYY'))
order by a.nome;
EXEC SQLCHECK('FDYDDOXHJVAQLTT');

--Ex9
select l.genero,
    l.titulo AS "Titulo",
    TO_CHAR(l.data_edicao, 'DD-MM-YYYY') as Data_Edicao,
    TRUNC(MONTHS_BETWEEN(SYSDATE, l.data_edicao) / 12) as "Num. de anos"
from livros L, editoras E, autores A
where l.codigo_editora = e.codigo_editora
and l.codigo_autor = a.codigo_autor
and upper(e.nome) = 'PORTO EDITORA'
and upper(l.genero) IN ('ROMANCE', 'POLICIAL', 'AVENTURA')
and upper(l.genero) = UPPER(a.genero_preferido)
order by l.genero, l.titulo;
EXEC SQLCHECK('FDSHQBGIDGMMMKI');

--Ex10
select nome
from clientes C, vendas V
where c.codigo_cliente = v.codigo_cliente
and TO_CHAR(v.data_venda, 'DY', 'NLS_DATE_LANGUAGE=ENGLISH') = 'SAT'
and TO_NUMBER(TO_CHAR(v.data_venda, 'DD')) BETWEEN 1 AND 7
and TO_NUMBER(TO_CHAR(v.data_venda, 'HH24')) >= 20
order by v.data_venda;
EXEC SQLCHECK('FDVTQDDJJOSWNKQ');

--Ex11
select A.nome, floor(months_between(SYSDATE, A.data_nascimento)/12) as Idade
from autores A, livros L
where a.codigo_autor = l.codigo_autor(+)
and l.codigo_livro is null;
EXEC SQLCHECK('FDCZJEHKLJPCOWU');

--Ex12
select nome
from autores
MINUS
select A.nome
from autores A, livros L 
where a.Codigo_Autor = l.Codigo_Autor
and To_Char(l.data_edicao, 'YYYY') != '2024'
order by nome;
EXEC SQLCHECK('FDXZQUGLBASGPVF');
