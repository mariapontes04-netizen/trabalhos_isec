exec naluno(2023133420);

--Ex.3
select a.nome,
       l.titulo,
       (select count(*)
            from livros L2 
            join editoras E2 on l2.codigo_editora = e2.codigo_editora
            where e2.nome = 'Leya' 
            and l2.codigo_autor = a.codigo_autor) as "LIVROS_LEYA",
       (select count(*)
            from livros L3
            where l3.codigo_autor = a.codigo_autor) as "TOTAL_DE_LIVROS"
from autores A
join livros L on a.codigo_autor = l.codigo_autor
join editoras E on l.codigo_editora = e.codigo_editora
where e.nome = 'Leya'
and l.preco_tabela = (
    select min(l2.preco_tabela)
    from livros L2 
    join editoras E2 on l2.codigo_editora = e2.codigo_editora
    where e2.nome = 'Leya'
);
EXEC SQLCHECK('FHJHHOMCPTVVKNH');

--Ex.4
select a.nome as "NOME",
    sum(CASE WHEN l.genero = a.genero_preferido THEN 1 ELSE 0 END) as "Genero Preferido",
    count(l.codigo_livro) as "Total de Livros"
from autores A, livros L
where a.codigo_autor = l.codigo_autor
group by a.codigo_autor, a.nome, a.genero_preferido
having count(l.codigo_livro) > 5
order by a.nome;
EXEC SQLCHECK('FHFQELJDGYAOLUQ');

--Ex.5
select 'O autor ' || a.nome || ' escreveu ' || count(l.codigo_livro) || 
        ' de ' || (select count(*) from livros l2 where l2.codigo_autor = a.codigo_autor) ||
        ' livros para a editora ' || e.nome as "RESULTADO"
from livros L, autores A, editoras E
where l.codigo_autor = a.codigo_autor
and l.codigo_editora = e.codigo_editora
and l.codigo_editora = (
    select codigo_editora
    from (
        select codigo_editora, sum(unidades_vendidas) as total_vendido
        from livros
        group by codigo_editora
        order by total_vendido ASC
    )
    where ROWNUM = 1
)
group by a.nome, a.codigo_autor, e.nome
order by a.nome;
EXEC SQLCHECK('FHMETHREKCIAMWP');

--Ex.6
select 'top ' || ROWNUM as "TOP",
        titulo as "TITULO",
        total_vendido as "SOMA"
from (
    select 
        l.titulo,
        SUM(c.quantidade) AS total_vendido
    from vendas v, contem c, livros l, autores a
    where v.codigo_venda = c.codigo_venda
    and c.codigo_livro = l.codigo_livro
    and l.codigo_autor = a.codigo_autor
    and v.data_venda > DATE '2025-01-10'
    group by l.titulo, a.nome, l.codigo_livro
    order by SUM(c.quantidade) desc
)
where ROWNUM <= 3;
EXEC SQLCHECK('FHFQLCOFFOHMNHS');

--Ex.7
select cl.nome as "NOME", l.titulo as "TITULO", TO_CHAR(v.data_venda, 'DD-MM-YYYY') as "DATA_DA_VENDA"
from clientes Cl, livros L, vendas V, contem C
where cl.codigo_cliente = v.codigo_cliente
and v.codigo_venda = c.codigo_venda
and c.codigo_livro = l.codigo_livro
and lower(cl.morada) like '%moura'
and v.data_venda = (
    select MAX(v2.data_venda)
    from vendas v2, contem c2 
    where v2.codigo_venda = c2.codigo_venda
    and v2.codigo_cliente = cl.codigo_cliente
)
order by cl.nome;
EXEC SQLCHECK('FHWXXZPGQKXCOJC');

--Ex.8
select "MES",
    "VENDAS_DO_MES",
    "VARIACAO_PERCENT"
from (
    select 
        To_Char(v.data_venda, 'YYYY/MM') as "MES",
        SUM(c.quantidade) as "VENDAS_DO_MES",
        ROUND(
            ((SUM(c.quantidade) - LAG(SUM(c.quantidade)) OVER (ORDER BY To_Char(v.data_venda, 'YYYY/MM'))) 
             / LAG(SUM(c.quantidade)) OVER (ORDER BY To_Char(v.data_venda, 'YYYY/MM'))) * 100, 2) as "VARIACAO_PERCENT"
    from vendas v, contem c
    where v.codigo_venda = c.codigo_venda
    group by To_Char(v.data_venda, 'YYYY/MM')
)
where "VARIACAO_PERCENT" > 100
and "MES" >= '2021/01'
order by "MES";
EXEC SQLCHECK('FHPKUUHHTYMVPIC');
