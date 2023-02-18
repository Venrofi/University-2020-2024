package com.example.teacherasistant

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.teacherasistant.database.entities.Mark
import com.example.teacherasistant.viewmodels.MarkListViewModel

class MarkListAdapter(
    private val _data: List<Mark>,
    private val _markListViewModel: MarkListViewModel
) : RecyclerView.Adapter<MarkListAdapter.ViewHolder>() {

    class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val markTextView: TextView
        val deleteButton: Button

        init {
            markTextView = view.findViewById(R.id.mark_list_item_mark_textview)
            deleteButton = view.findViewById(R.id.mark_list_item_delete_button)
        }
    }

    override fun onCreateViewHolder(viewGroup: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(viewGroup.context)
            .inflate(R.layout.mark_list_item, viewGroup, false)

        return ViewHolder(view)
    }

    override fun onBindViewHolder(viewHolder: ViewHolder, position: Int) {
        viewHolder.markTextView.text = _data[position].value.toString()
        viewHolder.deleteButton.setOnClickListener {
            _markListViewModel.deleteMark(_data[position])
        }
    }

    override fun getItemCount(): Int = _data.size
}