describe("distance (unit test)", function()
    pending("loads module", function()
        local g = require 'distance.credit'
    end)

    pending("accepts true solution", function()
        local g = require 'distance.credit'
        assert.has_no_error(function()
            g(function(A, B)
                assert(type(A) == 'string')
                assert(type(B) == 'string')
                assert(#A == #B)
                local result = {}
                local mismatches = 0
                for i = 1, #A do
                    local a = A:sub(i, i)
                    local b = B:sub(i, i)
                    assert(a == '0' or a == '1')
                    assert(b == '0' or b == '1')
                    if a == b then
                        table.insert(result, a)
                    else
                        if mismatches % 2 == 0 then
                            table.insert(result, a)
                        else
                            table.insert(result, b)
                        end
                        mismatches = mismatches + 1
                    end
                end
                if mismatches % 2 == 1 then
                    return nil
                end
                return table.concat(result)
            end)
        end)
    end)

    pending("accepts true solution 2", function()
        local g = require 'distance.credit'
        assert.has_no_error(function()
            g(function(A, B)
                assert(type(A) == 'string')
                assert(type(B) == 'string')
                assert(#A == #B)
                local result = {}
                local mismatches = 0
                for i = 1, #A do
                    local a = A:sub(i, i)
                    local b = B:sub(i, i)
                    assert(a == '0' or a == '1')
                    assert(b == '0' or b == '1')
                    if a == b then
                        local c = (a == '0') and '1' or '0'
                        table.insert(result, c)
                    else
                        if mismatches % 2 == 0 then
                            table.insert(result, a)
                        else
                            table.insert(result, b)
                        end
                        mismatches = mismatches + 1
                    end
                end
                if mismatches % 2 == 1 then
                    return nil
                end
                return table.concat(result)
            end)
        end)
    end)

    pending("throws on bad solutions", function()
        local g = require 'distance.credit'
        assert.has_error(function()
            g(function(A, B)
                assert(type(A) == 'string')
                assert(type(B) == 'string')
                assert(#A == #B)
                local result = {}
                local mismatches = 0
                for i = 1, #A do
                    local a = A:sub(i, i)
                    local b = B:sub(i, i)
                    if a == b then
                        table.insert(result, a)
                    else
                        if mismatches % 2 == 0 then
                            table.insert(result, a)
                        else
                            table.insert(result, b)
                        end
                        mismatches = mismatches + 1
                    end
                end
                if mismatches % 2 == 1 then
                    return nil
                end
                return table.concat(result)
            end)
        end)

        assert.has_error(function()
            g(function(A, B)
                assert(type(A) == 'string')
                assert(type(B) == 'string')
                assert(#A == #B)
                local result = {}
                local mismatches = 0
                for i = 1, #A do
                    local a = A:sub(i, i)
                    local b = B:sub(i, i)
                    assert(a == '0' or a == '1')
                    assert(b == '0' or b == '1')
                    if a == b then
                        table.insert(result, a)
                    else
                        if mismatches % 2 == 0 then
                            table.insert(result, a)
                        else
                            table.insert(result, b)
                        end
                        mismatches = mismatches + 1
                    end
                end
                return table.concat(result)
            end)
        end)
    end)
end)
