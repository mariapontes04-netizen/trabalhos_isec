exec naluno(2023133420);

--Ex.3
select count(codigo_livro) as "Total livros de Informática"
from livros
where genero like '%Informática'
and preco_tabela > 25;
EXEC SQLCHECK('FEKSNESCHSOLHAA');

--Ex.4
select count(codigo_livro) as "Total de Livros", 
    round(avg(preco_tabela),2) as "Preço Médio", 
    sum(unidades_vendidas) as "Total de livros vendidos"
from livros
where genero in ('Policial' , 'Romance');
EXEC SQLCHECK('FEPLBCEDUBEZITK');

--Ex.5
select distinct genero, count(codigo_livro) as "Num. Livros"
from livros
group by genero
order by count(codigo_livro), genero;
EXEC SQLCHECK('FENZFMTEPGWWJJB');

--Ex.6
select l.titulo,
    max(co.preco_unitario) as "P_MAIS_ALTO",
    min(co.preco_unitario) as "P_MAIS_BAIXO",
    round(AVG(co.preco_unitario), 1) as "P_MEDIO"
from livros L, contem Co, vendas V
where l.codigo_livro = co.codigo_livro
and co.codigo_venda = v.codigo_venda
and l.genero like '%Informática'
and l.data_edicao >= TO_DATE('2024-01-01', 'YYYY-MM-DD')
and l.data_edicao < TO_DATE('2024-02-01', 'YYYY-MM-DD')
group by l.titulo
order by max(co.preco_unitario), l.titulo;
EXEC SQLCHECK('FEUDQKPFBHEJKEX');

--Ex.7
select genero,
    max(preco_tabela) - min(preco_tabela) as  DIF_PRECOS,
    count(codigo_livro) as N_LIVROS
from livros
group by genero
order by genero asc;
EXEC SQLCHECK('FEENCUAGEOCELHN');

--Ex.8
select l.titulo, 
    l.preco_tabela as "PRECO", 
    SUM(co.quantidade) as "NUM_VENDIDOS",
    SUM(co.quantidade * l.preco_tabela) as "REC_ESPERADA",
    SUM(co.quantidade * co.preco_unitario) as "REC_EFECTIVA"
from livros L, contem Co, vendas V
where l.codigo_livro = co.codigo_livro
and co.codigo_venda = v.codigo_venda
and l.preco_tabela > 80
and To_Char(v.data_venda, 'YYYY') = '2024'
group by l.titulo, l.preco_tabela
order by l.titulo;
EXEC SQLCHECK('FEWQQBKHAMNEMRO');

--Ex.9
select genero,
    ceil(avg(preco_tabela)) as "Preço Médio"
from livros
group by genero
having count(codigo_livro)>20
order by avg(preco_tabela) asc, genero desc;
EXEC SQLCHECK('FENGOJZIXTYUNWF');

--Ex.10
select a.nome,
    min(l.preco_tabela) as "Preco do Mais Barato"
from autores A, livros L
where a.codigo_autor = l.codigo_autor
group by a.nome
having min(l.preco_tabela)>=35
order by "Preco do Mais Barato", a.nome;
EXEC SQLCHECK('FEFHOFLJGFPJOEM');

--Ex.11
select cl.nome,
    SUM(co.quantidade) as "N.Livros",
    ROUND(AVG(co.preco_unitario), 2) as "Preco Medio",
    COUNT(DISTINCT l.codigo_autor) as "N.Autor Diferent"
from clientes Cl, vendas V, contem Co, livros L
where cl.codigo_cliente = v.codigo_cliente
and v.codigo_venda = co.codigo_venda
and co.codigo_livro = l.codigo_livro
and cl.morada like '%Figueira da Foz'
group by cl.codigo_cliente, cl.nome
having sum(co.quantidade)<50
    and avg(co.preco_unitario)<11
    and count(distinct l.codigo_autor)>1
order by cl.nome;
EXEC SQLCHECK('FEDRYKSKONDRPFY');

--Ex.12
select a.nome as "NOME",
    CASE
        WHEN COUNT(l.codigo_livro) = 0 THEN 'Não escreveu Livros'
        ELSE 'Escreveu ' || COUNT(l.codigo_livro) || ' livros de ' || l.genero
    END AS "Num.de Livros que escreveu"
from autores A
left join livros L on a.codigo_autor = l.codigo_autor
where a.genero_preferido like '%Romance'
and trunc(MONTHS_BETWEEN(SYSDATE, a.data_nascimento) / 12) > 50
group by a.codigo_autor, a.nome, l.genero 
order by a.nome ASC, l.genero ASC;
EXEC SQLCHECK('FEQBPUSLXABOQIR');

--Ex.13
select lj.nome as "NOME_LOJA",
    sum(co.quantidade) as "QUANTIDADE_VENDIDA",
    round(avg(co.preco_unitario), 2) as "PRECO_MEDIO"
from lojas Lj, vendas V, Contem Co, livros L
where lj.codigo_loja = v.codigo_loja
and v.codigo_venda = co.codigo_venda
and co.codigo_livro = l.codigo_livro
and l.genero like '%Policial' 
and extract(YEAR FROM v.data_venda) = extract(YEAR FROM SYSDATE) 
group by lj.codigo_loja, lj.nome
having sum(co.quantidade) > 20 
order by "QUANTIDADE_VENDIDA" desc, "NOME_LOJA" asc; 
EXEC SQLCHECK('FERLCQSMTXFVRBN');

--Ex.14
select 'Week ' || TO_CHAR(data_transferencia, 'W') || ' of ' || TO_CHAR(data_transferencia, 'Month') as "MÊS",
    sum(quantidade) AS TOTAL_LIVROS_TRANSFERIDOS
from transferencias 
where extract(YEAR FROM data_transferencia) = extract(YEAR FROM SYSDATE)
and extract(MONTH FROM data_transferencia) IN (8, 9)
group by TO_CHAR(data_transferencia, 'Month'),
    TO_CHAR(data_transferencia, 'W'),
extract(MONTH FROM data_transferencia) 
order by extract(MONTH FROM data_transferencia) ASC, 
    TO_CHAR(data_transferencia, 'W') ASC; 
EXEC SQLCHECK('FEALQRONPDFGSOO');

--Ex.15
select
    Cl.Nome AS NOME,
    SUM(Co.Quantidade) AS QUANTIDADE_VENDIDA,
    COUNT(DISTINCT V.Codigo_Loja) AS NUM_LOJAS
from clientes Cl,vendas V, contem Co, livros L
where cl.codigo_cliente = v.codigo_cliente
and v.codigo_venda = co.codigo_venda
and co.codigo_livro = l.codigo_livro
and cl.morada like '%Barcelos'
and l.genero like '%Policial'
group by cl.codigo_cliente, cl.nome
having sum(co.quantidade*co.preco_unitario)>=100
order by cl.nome asc;
EXEC SQLCHECK('FEEPGLTOZCNETPZ');
