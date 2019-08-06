\i setup.sql

SELECT plan(5);

PREPARE edges AS
SELECT id, source, target, cost, reverse_cost  FROM edge_table;

SELECT isnt_empty('edges', 'Should be not empty to tests be meaningful');


CREATE OR REPLACE FUNCTION test_function()
RETURNS SETOF TEXT AS
$BODY$
DECLARE
params TEXT[];
subs TEXT[];
BEGIN
    params = ARRAY[
    '$$SELECT id, source, target, cost, reverse_cost  FROM edge_table WHERE id = 2 $$'
    ]::TEXT[];
    subs = ARRAY[
    'NULL',
    'NULL::BIGINT[]'
    ]::TEXT[];

    RETURN query SELECT * FROM no_crash_test('pgr_transitiveclosure', params, subs);

END
$BODY$
LANGUAGE plpgsql VOLATILE;

SELECT * FROM test_function();

ROLLBACK;
