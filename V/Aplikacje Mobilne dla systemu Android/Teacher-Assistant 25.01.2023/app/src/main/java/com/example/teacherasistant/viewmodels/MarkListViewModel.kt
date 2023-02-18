package com.example.teacherasistant.viewmodels

import android.content.Context
import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.asLiveData
import androidx.lifecycle.viewModelScope
import com.example.teacherasistant.database.AppDatabase
import com.example.teacherasistant.database.entities.Mark
import com.example.teacherasistant.repositories.MarkRepository
import kotlinx.coroutines.launch

class MarkListViewModel(private val _context: Context, subjectId: Long, studentId: Long) :
    ViewModel() {
    private val _markRepository =
        MarkRepository(AppDatabase.getInstance(_context).markDao(), subjectId, studentId)

    private val _marks: LiveData<List<Mark>> = _markRepository.marks.asLiveData()
    val marks: LiveData<List<Mark>>
        get() = _marks

    fun deleteMark(mark: Mark) = viewModelScope.launch {
        _markRepository.deleteMark(mark)
    }
}